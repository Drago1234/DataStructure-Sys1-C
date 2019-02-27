# BY SUBMITTING THIS FILE AS PART OF MY LAB ASSIGNMENT, I CERTIFY THAT
# ALL OF THE CONTENT OF THIS FILE WAS CREATED BY ME WITH NO
# ASSISTANCE FROM ANY PERSON OTHER THAN THE INSTRUCTOR OF THIS COURSE
# OR ONE OF OUR UNDERGRADUATE GRADERS. I UNDERSTAND THAT TO DO
# OTHERWISE IS A VIOLATION OF OHIO STATE UNIVERSITY'S ACADEMIC INTEGRITY
# POLICY.

#Makefile is very strict on spacing:No space after:
all:lab4

lab4:lab4main.o computeCumulative.o computeCurrentGrade.o computeOneFinalGrade.o freeAllNode.o getAndFillNode.o getNodeByName.o getNodeByID.o getOption.o insertNode.o isIdExist.o opt1PrintSingleStudentByID.o opt2PrintSingleStudentByName.o opt3PrintAllStudents.o opt4RecalculateSingleStudentByID.o opt5ReculculateAllStudents.o opt6InsertNewScore.o opt7CalculateFinalGrade.o opt8AddNewStudentFromStdin.o opt9DeleteSingleStudentByID.o printHeader.o printAndComputeAllAverage.o printLine.o printWholeList.o writeClassToDisk.o
	gcc lab4main.o computeCumulative.o computeCurrentGrade.o computeOneFinalGrade.o freeAllNode.o getAndFillNode.o getNodeByName.o getNodeByID.o getOption.o insertNode.o isIdExist.o opt1PrintSingleStudentByID.o opt2PrintSingleStudentByName.o opt3PrintAllStudents.o opt4RecalculateSingleStudentByID.o opt5ReculculateAllStudents.o opt6InsertNewScore.o opt7CalculateFinalGrade.o opt8AddNewStudentFromStdin.o opt9DeleteSingleStudentByID.o printHeader.o printAndComputeAllAverage.o printLine.o printWholeList.o writeClassToDisk.o -o lab4

lab4main.o:lab4main.c lab4.h
	gcc -ansi -pedantic -c -g lab4main.c

computeCumulative.o:computeCumulative.c lab4.h
	gcc -ansi -pedantic -c -g computeCumulative.c

computeCurrentGrade.o:computeCurrentGrade.c lab4.h
	gcc -ansi -pedantic -c -g computeCurrentGrade.c

computeOneFinalGrade.o:computeOneFinalGrade.c lab4.h
	gcc -ansi -pedantic -c -g computeOneFinalGrade.c

freeAllNode.o:freeAllNode.c lab4.h
	gcc -ansi -pedantic -c -g freeAllNode.c

getAndFillNode.o:getAndFillNode.c lab4.h
	gcc -ansi -pedantic -c -g getAndFillNode.c

getNodeByName.o:getNodeByName.c lab4.h
	gcc -ansi -pedantic -c -g getNodeByName.c

getNodeByID.o:getNodeByID.c lab4.h
	gcc -ansi -pedantic -c -g getNodeByID.c

getOption.o:getOption.c lab4.h
	gcc -ansi -pedantic -c -g getOption.c

insertNode.o:insertNode.c lab4.h
	gcc -ansi -pedantic -c -g insertNode.c

isIdExist.o:isIdExist.c lab4.h
	gcc -ansi -pedantic -c -g isIdExist.c

opt1PrintSingleStudentByID.o:opt1PrintSingleStudentByID.c lab4.h
	gcc -ansi -pedantic -c -g opt1PrintSingleStudentByID.c

opt2PrintSingleStudentByName.o:opt2PrintSingleStudentByName.c lab4.h
	gcc -ansi -pedantic -c -g opt2PrintSingleStudentByName.c

opt3PrintAllStudents.o:opt3PrintAllStudents.c lab4.h
	gcc -ansi -pedantic -c -g opt3PrintAllStudents.c

opt4RecalculateSingleStudentByID.o:opt4RecalculateSingleStudentByID.c lab4.h
	gcc -ansi -pedantic -c -g opt4RecalculateSingleStudentByID.c

opt5ReculculateAllStudents.o:opt5ReculculateAllStudents.c lab4.h
	gcc -ansi -pedantic -c -g opt5ReculculateAllStudents.c

opt6InsertNewScore.o:opt6InsertNewScore.c lab4.h
	gcc -ansi -pedantic -c -g opt6InsertNewScore.c

opt7CalculateFinalGrade.o:opt7CalculateFinalGrade.c lab4.h
	gcc -ansi -pedantic -c -g opt7CalculateFinalGrade.c

opt8AddNewStudentFromStdin.o:opt8AddNewStudentFromStdin.c lab4.h
	gcc -ansi -pedantic -c -g opt8AddNewStudentFromStdin.c

opt9DeleteSingleStudentByID.o:opt9DeleteSingleStudentByID.c lab4.h
	gcc -ansi -pedantic -c -g opt9DeleteSingleStudentByID.c

printHeader.o:printHeader.c lab4.h
	gcc -ansi -pedantic -c -g printHeader.c

printAndComputeAllAverage.o:printAndComputeAllAverage.c lab4.h
	gcc -ansi -pedantic -c -g printAndComputeAllAverage.c

printLine.o:printLine.c lab4.h
	gcc -ansi -pedantic -c -g printLine.c

printWholeList.o:printWholeList.c lab4.h
	gcc -ansi -pedantic -c -g printWholeList.c

writeClassToDisk.o:writeClassToDisk.c lab4.h
	gcc -ansi -pedantic -c -g writeClassToDisk.c

clean:
	rm -rf *.o lab4
