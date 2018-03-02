

# iterate directories

for inDir in test/input/; do
	for t in inDir/; do
		output.exe -testmode < t > /test/output/t.cout
		diff test/output/t.cout test/inDir/expectedOutput/t.cout
	done
done

