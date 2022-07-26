encryption.exe

for /L %%B in (1,1,10) do echo "">"test_%%B.txt"

xcopy test.txt test_1.txt /Y
encryption.exe k
encryption.exe c test_1.txt
del test_1.txt
encryption.exe d #test_1.txt#
test_1.txt

xcopy test.txt test_2.txt /Y /F
encryption.exe k 1
encryption.exe c test_2.txt
del test_2.txt
encryption.exe d #test_2.txt#
test_2.txt

xcopy test.txt test_3.txt /Y
encryption.exe k 10
encryption.exe c test_3.txt
del test_3.txt
encryption.exe d #test_3.txt#
test_3.txt

xcopy test.txt test_4.txt /Y
encryption.exe k 17 19
encryption.exe c test_4.txt
del test_4.txt
encryption.exe d #test_4.txt#
test_4.txt

xcopy test.txt test_5.txt /Y
encryption.exe k 909091 99990001
encryption.exe c test_5.txt
del test_5.txt
encryption.exe d #test_5.txt#
test_5.txt

xcopy test.txt test_6.txt /Y
encryption.exe k 3 99990001
encryption.exe c test_6.txt
del test_6.txt
encryption.exe d #test_6.txt#
test_6.txt

xcopy test.txt test_7.txt /Y
encryption.exe k 12345
encryption.exe c test_7.txt
del test_7.txt
encryption.exe d #test_7.txt#
test_7.txt

xcopy test.txt test_8.txt /Y
encryption.exe k
encryption.exe c test_8.txt
del test_8.txt
encryption.exe d #test_8.txt#
test_8.txt

xcopy test.txt test_9.txt /Y
encryption.exe k
encryption.exe c test_9.txt
del test_9.txt
encryption.exe d #test_9.txt#
test_9.txt

xcopy test.txt test_10.txt /Y
encryption.exe k
encryption.exe c test_10.txt
del test_10.txt
encryption.exe d #test_10.txt#
test_10.txt 

for /L %%B in (1,1,10) do del "test_%%B.txt" /q
for /L %%B in (1,1,10) do del "#test_%%B.txt#" /q