cat /etc/passwd |\
   	sed '/^#/d' |\
   	awk 'NR % 2 == 0' |\
   	sed 's/:.*//' |\
   	rev | sort -r |\
   	awk "NR >= /$FT_LINE1 && NR <= /$FT_LINE2" |\
   	awk '{printf "%s, ", $0}' |\
	sed 's/, $/./'
