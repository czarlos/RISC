rm ./*.pb.*

for f in ./*.proto
do
	protoc $f -I=. --cpp_out=./
done
