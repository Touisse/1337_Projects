#!/bin/bash

printf "#Architecture: "
 uname -a

printf "#CPU physical : "
 nproc --a

printf "#vCPU : "
 cat /proc/cpuinfo | grep processor | wc -l

printf "#Memory Usage: "
 free -m | grep Mem |awk '{printf"%d/%dMB (%.2f%%)\n", $3, $2, $3/$2 * 100}'

printf "#Disk Usage: "
 df -BM -a | grep /dev/mapper/ | awk '{sum += $3}END{print sum}' | tr -d '\n'
printf "/"
df -BG | grep /dev/mapper/ | awk '{ft += $2} END {print ft}' | tr -d '\n'
printf "Gb ("
 df -BM -a | grep /dev/mapper/ | awk '{sum1+=$3 ; sum2+=$4} END {printf "%d", sum1 / sum2 * 100}' | tr -d '\n'
printf "%%)\n"

printf "#CPU load: "
 mpstat | grep all | awk '{printf "%.2f%%\n", 100-$13}'

printf "#Last boot: "
 who -b | awk '{print" " $3" "$4" "$5}'

printf "#LVM use: "
if [ "$(lsblk | grep lvm | wc -l)" != 0 ] ; then printf "yes\n" ; else printf "no\n" ; fi

printf "#Connexions TCP : "
 ss | grep -i  tcp | wc -l | tr -d  '\n'
printf " ESTABLISHED\n"

printf "#User log: "
who | wc -l

printf "#Network: IP "
 hostname -I | tr -d '\n'
printf " ("
 ip a | grep link/ether | awk '{print $2}' | tr -d '\n'

printf ")\n"

printf "#Sudo : "
 cat /var/log/auth.log | grep -a sudo | grep -a 'COMMAND=' | wc -l | tr -d '\n'
printf " cmd\n"
