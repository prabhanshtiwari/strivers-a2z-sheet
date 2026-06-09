# Pattern 20 — Symmetric Hourglass Star Pattern

## What Does the Pattern Look Like?

For `N = 5`, the output is:

```
*        *
**      **
***    ***
****  ****
**********
****  ****
***    ***
**      **
*        *
```

The pattern has `2N - 1` rows total (for N=5, that's **9 rows**).

---

## Key Observation: Why Can't We Use Symmetry Splitting?

In some earlier patterns, you could split the pattern into two halves (top and bottom) and solve each separately, because each half was **exactly symmetrically opposite**. Pattern 20 **cannot** be split that way.

Why? Because there is only a **single middle line** (`**********`) — not two. If that middle row appeared twice, we could treat it as two separate symmetric halves. But with just one middle row, we must handle the transition carefully inside a **single loop**.

---

## Pattern Analysis (Row by Row)

| Row (i) | Stars (each side) | Spaces |
|---------|-------------------|--------|
| 1       | 1                 | 8      |
| 2       | 2                 | 6      |
| 3       | 3                 | 4      |
| 4       | 4                 | 2      |
| 5       | 5                 | 0      |
| 6       | 4                 | 2      |
| 7       | 3                 | 4      |
| 8       | 2                 | 6      |
| 9       | 1                 | 8      |

- Initial spaces = `2N - 2` = 8 (for N=5)
- Each row prints: **[stars] [spaces] [stars]**
- This is similar to right-angle triangle patterns, but mirrored

---

## Deriving the Formulas

### Outer Loop
The outer loop always runs **2N - 1** times.

```
for (int i = 1; i <= 2 * n - 1; i++)
```

### Stars Formula
- **When `i <= N`** (upper half including middle): stars = `i`
- **When `i > N`** (lower half): stars = `2N - i`

This is **exactly the same logic** used in Pattern 10 (the diamond/rhombus), which was studied earlier.

```
int stars = (i <= n) ? i : (2 * n - i);
```

### Spaces Formula
- Initial spaces = `2N - 2`
- As we go **down toward the middle**: spaces **decrease by 2** each row
- After the middle row: spaces **increase by 2** each row

```
// Before or at middle row
if (i < n)   spaces -= 2;

// After middle row
else         spaces += 2;
```

> **Note:** In the video, a mistake was made initially — the instructor accidentally set spaces as decreasing when it should have been increasing below the midpoint. He caught the bug and fixed it by swapping the `+=` and `-=`.

---

## How Each Row is Printed

Every row follows this structure:

```
[stars printed] → [spaces printed] → [stars printed again] → [newline]
```

The left stars and right stars are **always equal in count** for any given row.

---

## Full Code with Detailed Comments

```cpp
void print20(int n) {

    // The outer loop runs 2n-1 times total
    // This covers both the upper half (rows 1 to n) 
    // and the lower half (rows n+1 to 2n-1)
    
    // Initialize spaces to the maximum value: 2n-2
    // Row 1 has the most spaces (widest gap between stars)
    int spaces = 2 * n - 2;

    for (int i = 1; i <= 2 * n - 1; i++) {

        // ── CALCULATE NUMBER OF STARS FOR THIS ROW ──
        // Upper half (i <= n): star count equals row number
        // Lower half (i > n): star count decreases using formula 2n - i
        // Example (n=5): row 6 → 2*5 - 6 = 4 stars, row 7 → 3 stars, etc.
        int rows = (i <= n) ? i : (2 * n - i);

        // ── PRINT LEFT STARS ──
        // Print 'rows' number of stars on the left side
        for (int j = 1; j <= rows; j++) {
            cout << "*";
        }

        // ── PRINT SPACES (middle gap) ──
        // Print the current number of spaces between left and right stars
        for (int j = 1; j <= spaces; j++) {
            cout << " ";
        }

        // ── PRINT RIGHT STARS ──
        // Mirror of the left side — same number of stars
        for (int j = 1; j <= rows; j++) {
            cout << "*";
        }

        // ── END OF ROW ──
        cout << endl;

        // ── UPDATE SPACES FOR NEXT ROW ──
        // Before reaching the middle row (i < n): gap is shrinking → subtract 2
        // After reaching the middle row (i >= n): gap is growing → add 2
        // Note: at i == n (middle row), we start increasing for the next row
        if (i < n) {
            spaces -= 2;   // Spaces decrease as we approach the center
        } else {
            spaces += 2;   // Spaces increase as we move away from the center
        }
    }
}
```

---

## Tracing the Logic for N = 5

| i  | `rows` (formula)    | `spaces` at start | Left stars | Gap   | Right stars |
|----|---------------------|--------------------|------------|-------|-------------|
| 1  | i=1                 | 8                  | `*`        | 8 sp  | `*`         |
| 2  | i=2                 | 6                  | `**`       | 6 sp  | `**`        |
| 3  | i=3                 | 4                  | `***`      | 4 sp  | `***`       |
| 4  | i=4                 | 2                  | `****`     | 2 sp  | `****`      |
| 5  | i=5                 | 0                  | `*****`    | 0 sp  | `*****`     |
| 6  | 2×5−6 = 4           | 2                  | `****`     | 2 sp  | `****`      |
| 7  | 2×5−7 = 3           | 4                  | `***`      | 4 sp  | `***`       |
| 8  | 2×5−8 = 2           | 6                  | `**`       | 6 sp  | `**`        |
| 9  | 2×5−9 = 1           | 8                  | `*`        | 8 sp  | `*`         |

---

## Common Mistake to Avoid

The instructor initially had the `spaces` update logic **inverted** — subtracting where it should add and vice versa. This caused wrong output.

**Wrong (buggy version):**
```cpp
if (i < n) spaces += 2;   // WRONG: this grows the gap when it should shrink
else       spaces -= 2;   // WRONG: this shrinks when it should grow
```

**Correct version:**
```cpp
if (i < n) spaces -= 2;   // Correct: shrinks gap as we go toward center
else       spaces += 2;   // Correct: grows gap as we go away from center
```

Always **verify direction** of space change by tracing manually before running.

---

## Connection to Previous Patterns

| Pattern | Concept Used in Pattern 20 |
|---------|---------------------------|
| Pattern 10 (Diamond/Rhombus) | The `stars = 2n - i` formula for the lower half |
| Right-angle triangle patterns | The basic star-printing inner loop structure |

The instructor explicitly said: *"We have done this in Pattern 10. The moment it crosses the Nth row, stars = 2N - i."*

---

## Summary of Key Formulas

```
Total rows       = 2N - 1
Stars per row    = i          (when i <= N)
                 = 2N - i     (when i > N)
Initial spaces   = 2N - 2
Space change     = -2 per row (while i < N)
                 = +2 per row (while i >= N)
```

<!-- IMAGE: Diagram showing the hourglass shape with labeled rows, star counts on both sides, and space counts in the middle for N=5 -->

<!-- Transcript:
```
Now, it's about the next pattern, which
is the pattern 20.
So, can I say over here,
it's again the same pattern.
But this time, can you break down into
symmetry? You cannot because there is
just if I if I carefully show you,
there's this one line. Over here, you
could because it was exactly
symmetrically opposite. But this is not
symmetrically. There is just a single
line. Had this line been twice, we could
have done it accordingly. But no issues.
Maybe we can figure out a way and we can
do it. Because these are nothing but
similar to right angle triangle.
Isn't it? It's similar to right angle
So, we will first have a look.
N over here, assume it's five.
It's like 1 2 3 4 5 6 7 8 9. Something I
know for sure is 2 N minus one times is
what the outer loop will run. 2 N minus
one times is what the outer loop will
run. This is something for sure.
So, if I look at this, we're actually
printing like one star,
a lot of spaces. How many? Let's count.
1 2 3 4 5 6 7 8 spaces to start off
with.
One star, eight space, one star.
Two star, two star, six space. Three
star, three star, four space. Four star,
four star, two space. And then
five star, zero space, five star. And
then
four star, four star.
So, can I say
after
can I say after the fifth row,
can I say after the fifth row, there
will be a subtle change? The moment you
are at the row
five or maybe
N by two. The moment you are at the row
N by two, on the next step, there will
be a change. And the change is very
subtle.
The the space will increase. Till here,
it was decreasing. The space was
decreasing. But whenever we reach here,
the space the space starts to increase.
The space will start to increase.
Right? And what happens
to the rows?
You're just printing four, then three.
We had done this. Yes, we have done
this. If we go ahead, we have done this
in the pattern 10. So, we'll go ahead
and look at the pattern 10.
How are we doing it? Previously, saying
the stars will be 2 N minus I the moment
it
crosses
the N th guy. Right? So, this is what we
will do over here as well.
The moment it crosses this guy,
it's going to be nothing but
the number of stars.
Till here, it was very simple. Whatever
is the row number, that's the star. But
the moment it crosses, it will be 2 N
minus I. Again, very obvious. For the
sixth, 2 into 5 - 6, that's four stars.
Done.
So, I have figured out all the formulas,
everything. Now, it's time to go and
quickly code this up.
It's like void print 20 int n. And I
know one thing for sure, this is going
to run till 2 into n - 1 and I plus
plus. That's something which we know.
Now, what are we printing? Stars at
first,
spaces,
and then stars. Let's print the stars. I
know stars The number of stars are very
simple.
The number of stars depends like it will
be rows, but if if if the I has crossed
the n, then the stars will be Let's
throw in the sense I. Stars will be
2 into n minus the row number.
We can just print the stars now.
For int j equal to 1, we can go ahead
and print those many stars.
And we can go ahead and do j plus plus
and see out of star. That's it.
And over here, you can just copy paste
the same thing and you can see this. So,
this will print all the stars. What
about the spaces? You know the spaces
how they increase? Maybe you can keep
the spaces initially as If you remember,
the initial space was eight. So, instead
of keeping it as eight, you can say 2n
minus 2. I think we did a mistake here
by keeping the space as
initial space as Okay, it was right. It
was zero.
This will not be eight. Instead of this,
this will be 2 into n minus 2. My bad.
I did a mistake there, but uh
nevertheless.
So,
Okay, 2n minus 2 is the initial spaces
that we start off with.
And then while going, we can do like j
equal to 1 and we need these many
spaces. So, j plus plus and you can just
go ahead and say space.
At the end of the day, you can just see
out endl.
And if I is lesser than equal to
Like lesser than Sorry. Lesser than n,
then you say spaces will be increased by
two. Else, spaces will be decreased by
two. This is what you will do to the
spaces. And this is pattern number 20,
so let's go ahead and print this and see
if it is running fine or not.
Okay, we have an issue.
Looks like there was an issue while
printing it.
Why did it happen? Let's quickly have a
look.
If I made a mistake, space will be minus
two here and this is where the space
increases.
Okay, let's run it quickly. Let's
compile and see.
Yeah, that's it. It's perfect.
```
---
```
*        *
**      **
***    ***
****  ****
**********
****  ****
***    ***
**      **
*        *
```


---
I have given you the english transcript of the video.and the pattern,  i want you to make notes in md format in english using the transcript and the notes that i made by following the video, i want you to create most detailed notes ever . get the information and code related stuff only from the transcript. i also want you to describe my code using helpful comments so that it will be easy to understand, i want you to make the notes in detailed manner and never miss any point -->