echo "Enter a number"
read n

for (( i = 1; i<=n;i++))
do 
    if(( num % i == 0))
    then
        echo $i
     fi
done  