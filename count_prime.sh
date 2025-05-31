echo "Enter Number"
read num
for (( i = 2; i < num ; i++ ))
do 

    is_prime=1
    for (( j = 2 ; j < i ; j++ ))
    do
        if (( i % j == 0))
        then 
            is_prime=0
            break
        fi
    done
    if (( is_prime==1))
    then 
    echo $i
    fi
done