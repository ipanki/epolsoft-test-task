if [ -z $1 ]
then
    echo "Usage: test.sh <file with test data>"
    exit 1
fi
COUNT=$(head -n 1 test.txt | wc -w)
RESULT=$(head -n 2 $1 | ./match $COUNT | tail -n 1)
EXPECTED=$(tail -n 1 $1)

cat $1

if [ $RESULT -eq $EXPECTED ]
then
    echo "Test passed"
else
    echo "Test failed (expected ${EXPECTED}, got ${RESULT})"
    exit 1
fi
