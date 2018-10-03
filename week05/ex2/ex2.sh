for i in {0..512} 
do  
	new=$(cat ex2.txt | tail -n 1)
	echo "$(($new + 1))" >> ex2.txt
	sleep 1
done


