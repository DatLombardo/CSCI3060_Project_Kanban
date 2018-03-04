

# iterate directories

INPUTPATH=/testing/input
OUTPUTPATH=output

# cp ../output.exe output.exe


	# echo $i
for i in testing/input/*.inp; do
    base=${i##*/}
    testname=${base%.*}

    testing/output.exe -testmode testing/output/$testname.fexp < "$i" > testing/output/$testname.cexp
done

    # echo | ./output.exe -testmode output/$trans$transfile.fout < $t

    # compare output files

