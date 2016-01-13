del handler\*
del message\*

protoc --cpp_out=../message *.proto
meloton-handler-generator.exe D:\Git\meloton-cli\proto\ D:\Git\meloton-cli\proto\

copy message/MessageUtils.h ../handler/
 
 
pause