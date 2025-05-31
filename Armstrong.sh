echo "Enter a number "
read num

original=$num
n=${#num}
sum=0

while [ $num -gt 0 ]
do 
    remaninder=$(( num % 10 ))
    power=1
    