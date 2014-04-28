
#!bin/bash

FileName=mat_prog.m
cat > $FileName <<EOF
%This is a matlab script

rn=round(random('normal',256,512,1000000,1));
rn(find(rn<64))=[];
rn(find(rn>1024))=[];

x=unique(rn);
hist(rn,x);

fid=fopen(`myfile.txt`,'w');
fprintf(fid,'%d\n',rn);
fclose(fid);
EOF
