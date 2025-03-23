# Github History Graffiti

![Github History Graffiti Example](./img/example.jpg)

This is a very simple stupid history graffiti program. This means and allows
you to put text and put "Graffiti" on your github contribution history.

## How

A very simple (UNIX) C program that runs one simple shell command:

```bash
git add . && git commit -m 'Commit Position: #<num> try <try>' --no-edit --date="$(date -uRd $(date -ud '2025-01-01 + <days> days' +%Y-%m-%d))"
```

Broken down this "simple" command looks like this:

```bash
# Add all files updated
git add .

# Convert Days in Year format to YYYY/MM/DD
DAYSINYEAR=$(date -ud '2025-01-01 + <days> days' +%Y-%m-%d)
# Convert YYYY/MM/DD to DDD, DD MMM YYYY hh:mm:ss +0000
DATE=$(date -uRd $DAYSINYEAR)
# Commit all update files with `-m` comment, do not edit, and a custom date.
git commit -m 'Commit Position: #<num> try <try>' --no-edit --date="$DATE"
```

## Why

Because it was a fun and small took-longer-than-expected project.

# Similar

https://github.com/gelstudios/gitfiti
