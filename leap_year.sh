echo "Enter an year"
read n
if (( ((n%4 ==0)) && ((n%100 !=0)) ||((n%400 ==0))))
then
echo "Leap year"
else
echo "Not Leap year"
fi