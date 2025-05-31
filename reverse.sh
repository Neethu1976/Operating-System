echo "Enter a number :"
read num
temp=0
while [ $num -gt 0 ]
do 
    rev=$((num % 10 ))
    temp=$((temp * 10 + rev))
    num=$((num/10))
done
echo "Reversed number is : $temp"