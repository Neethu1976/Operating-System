#!/bin/bash

echo "Enter a String"
read num
rev=$(echo "$num" | rev)
echo "Reverse: $rev"

if [[ "$num" == "$rev" ]]; then
    echo "Palindrome"
else
    echo "Not a palindrome"
fi
