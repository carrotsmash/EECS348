all: program1 program2
program1: sales_report.c
	gcc sales_report.c -o program1
program2: nfl_scores.c
	gcc nfl_scores.c -o program2