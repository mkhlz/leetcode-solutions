# User Activity for the Past 30 Days - Complete Guide

## Problem Overview

**Goal**: Count unique active users for each day over a 30-day period ending on `2019-07-27` (inclusive).

**Definition**: A user is "active" on a day if they performed at least one activity on that day.

---

## Sample Data Structure

```
Activity Table:
┌─────────┬───────────────┬───────────────┐
│ user_id │ activity_date │ activity_type │
├─────────┼───────────────┼───────────────┤
│    1    │  2019-07-25   │     login     │
│    1    │  2019-07-25   │     post      │
│    2    │  2019-07-25   │     login     │
│    1    │  2019-07-26   │     comment   │
│    3    │  2019-07-27   │     login     │
│    1    │  2019-07-27   │     like      │
│    2    │  2019-07-27   │     share     │
└─────────┴───────────────┴───────────────┘
```

---

## Understanding "30 Days Inclusive"

When the problem says "30 days ending 2019-07-27 **inclusively**":

```
Day 30 (start) ← ... ← Day 2 ← Day 1 (end)
2019-06-28              2019-07-26   2019-07-27
```

**Key Insight**: July 27th counts as one of the 30 days!

### Date Calculation
- End date: `2019-07-27` (inclusive)
- Start date: `DATE_SUB('2019-07-27', INTERVAL 29 DAY)` = `2019-06-28`
- Total days: 30 (including both endpoints)

---

## The Core Challenge: Counting Distinct Users

### Raw Data Problem
```
Same user, same day, multiple activities:
┌─────────┬───────────────┬───────────────┐
│ user_id │ activity_date │ activity_type │
├─────────┼───────────────┼───────────────┤
│    1    │  2019-07-25   │     login     │  ← User 1 on July 25
│    1    │  2019-07-25   │     post      │  ← User 1 on July 25 (again!)
│    2    │  2019-07-25   │     login     │  ← User 2 on July 25
└─────────┴───────────────┴───────────────┘

Question: How many active users on 2019-07-25?
Answer: 2 (not 3!) - we count User 1 only once
```

### Solution: COUNT(DISTINCT user_id)
- Counts each unique user only once per day
- Handles multiple activities by same user correctly

---

## Query Building Process

### Step 1: Basic Structure
```sql
SELECT activity_date AS day, COUNT(DISTINCT user_id) AS active_users
FROM Activity
```

### Step 2: Add Date Filtering
```sql
WHERE activity_date BETWEEN 
    DATE_SUB('2019-07-27', INTERVAL 29 DAY) AND '2019-07-27'
```

### Step 3: Group by Day
```sql
GROUP BY activity_date
```

### Final Query
```sql
SELECT activity_date AS day, COUNT(DISTINCT user_id) AS active_users
FROM Activity
WHERE activity_date BETWEEN 
    DATE_SUB('2019-07-27', INTERVAL 29 DAY) AND '2019-07-27'
GROUP BY activity_date;
```

---

## Expected Output Format

```
Result Table:
┌─────────────┬──────────────┐
│     day     │ active_users │
├─────────────┼──────────────┤
│ 2019-07-25  │      2       │
│ 2019-07-26  │      1       │
│ 2019-07-27  │      3       │
└─────────────┴──────────────┘
```

**Important Note**: Days with zero activity won't appear in this result set!

---

## Common Pitfalls and Solutions

### ❌ Wrong: Using 30-day interval
```sql
-- This excludes the end date from the 30 days
DATE_SUB('2019-07-27', INTERVAL 30 DAY)
```

### ✅ Correct: Using 29-day interval
```sql
-- This includes the end date as one of the 30 days
DATE_SUB('2019-07-27', INTERVAL 29 DAY)
```

### ❌ Wrong: Counting all activities
```sql
-- This counts activities, not unique users
COUNT(user_id)
```

### ✅ Correct: Counting distinct users
```sql
-- This counts each user only once per day
COUNT(DISTINCT user_id)
```

---

## Debugging Tips

### Check Your Date Range
```sql
-- Test your date calculation
SELECT DATE_SUB('2019-07-27', INTERVAL 29 DAY) as start_date,
       '2019-07-27' as end_date,
       DATEDIFF('2019-07-27', DATE_SUB('2019-07-27', INTERVAL 29 DAY)) + 1 as total_days;
```

Expected result: `total_days = 30`

### Verify Distinct Counting
```sql
-- For a specific date, check both counts
SELECT activity_date,
       COUNT(*) as total_activities,
       COUNT(DISTINCT user_id) as unique_users
FROM Activity 
WHERE activity_date = '2019-07-25'
GROUP BY activity_date;
```

---

## Key Learning Points

1. **"Inclusive" dates matter** - always clarify whether endpoints are included
2. **DISTINCT is crucial** - when counting unique entities across multiple rows
3. **Date arithmetic** - subtract one less day when the end date is inclusive
4. **GROUP BY behavior** - only shows groups that exist (no zero-activity days)
5. **Column aliases** - use AS to match expected output format

---

## Extension: What About Missing Days?

The current solution only shows days with activity. If you needed to show ALL 30 days (including days with 0 users), you'd need a different approach involving:

1. **Generate a date series** for all 30 days
2. **LEFT JOIN** with your activity aggregation
3. **COALESCE** to show 0 for missing days

But for this specific problem, showing only active days was sufficient!