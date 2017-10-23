
rm -rf secret/
mkdir secret/

python3 gen1.py n=100000 c=0 m=110000 k=100 1 > secret/1-1.in
python3 gen1.py n=100000 c=0 m=200000 k=100 2 > secret/1-2.in
python3 gen1.py n=99990 c=10 m=110000 k=100 3 > secret/1-3.in
python3 gen1.py n=99990 c=10 m=200000 k=100 4 > secret/1-4.in
python3 gen1.py n=90000 c=10000 m=200000 k=100 5 > secret/1-5.in
python3 gen1.py n=90000 c=10000 m=200000 k=50000 6 > secret/1-6.in
python3 gen1.py n=10000 c=90000 m=200000 k=100 7 > secret/1-7.in
python3 gen1.py n=0 c=100000 m=200000 k=100 8 > secret/1-8.in
echo done 1

python3 gen2.py n=100000 k=300 100 > secret/2-1.in
echo done 2

python3 gen3.py n=50000 k=0 1 > secret/3-1.in
python3 gen3.py n=50000 k=1 2 > secret/3-2.in
python3 gen3.py n=50000 k=100000 3 > secret/3-3.in
echo done 3

python3 gen4.py n=300 1 > secret/4-1.in
echo done 4
