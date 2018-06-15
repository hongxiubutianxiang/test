const
table:array [1..32] of record
zone:string[4]; time:real;
end
=
(
(zone:'UTC';time:0),
(zone:'GMT';time:0),
(zone:'BST';time:1),
(zone:'IST';time:1),
(zone:'WET';time:0),
(zone:'WEST';time:1),
(zone:'CET';time:1),
(zone:'CEST';time:2),
(zone:'EET';time:2),
(zone:'EEST';time:3),
(zone:'MSK';time:3),
(zone:'MSD';time:4),
(zone:'AST';time:-4),
(zone:'ADT';time:-3),
(zone:'NST';time:-3.5),
(zone:'NDT';time:-2.5),
(zone:'EST';time:-5),
(zone:'EDT';time:-4),
(zone:'CST';time:-6),
(zone:'CDT';time:-5),
(zone:'MST';time:-7),
(zone:'MDT';time:-6),
(zone:'PST';time:-8),
(zone:'PDT';time:-7),
(zone:'HST';time:-10),
(zone:'AKST';time:-9),
(zone:'AKDT';time:-8),
(zone:'AEST';time:10),
(zone:'AEDT';time:11),
(zone:'ACST';time:9.5),
(zone:'ACDT';time:10.5),
(zone:'AWST';time:8));
var
n,i,j,k:byte;
t1,t2:real;
h,m:byte;code:integer;
s,r:string;
ap:boolean;
begin
readln(n);
for i:=1 to n do begin
readln(s);
while s[length(s)]=' ' do s[0]:=pred(s[0]);

for j:=length(s) downto 1 do if s[j]=' ' then break;
r:=copy(s,j+1,length(s)-j); s:=copy(s,1,j-1);
for j:=1 to 32 do if r=table[j].zone then t2:=table[j].time;

for j:=length(s) downto 1 do if s[j]=' ' then break;
r:=copy(s,j+1,length(s)-j); s:=copy(s,1,j-1);
for j:=1 to 32 do if r=table[j].zone then t1:=table[j].time;

if s='noon' then begin h:=12; m:=0; ap:=true; end else
if s='midnight' then begin h:=12; m:=0; ap:=false; end else
begin
if s[length(s)-3]='a' then ap:=true else ap:=false;
s:=copy(s,1,length(s)-5);
val(copy(s,1,pos(':',s)-1),h,code);
val(copy(s,pos(':',s)+1,length(s)-pos(':',s)),m,code);
if not ap then h:=h+12;
end;

t1:=-t1+t2;
h:=h+trunc(t1);
m:=m+30*(trunc(t1*2)-trunc(t1)*2);
while m>=60 do begin h:=h+1; m:=m-60; end;
while h>=24 do h:=h-24;
if h>=12 then begin h:=h-12; ap:=false; end else ap:=true;
if h=0 then begin h:=12; ap:=not ap; end;
if (h=12) and (m=0) then
if ap then writeln('noon') else writeln('midnight') else begin
write(h,':');if m<10 then write('0');write(m,' ');
if ap then write('a') else write('p');writeln('.m.');
end;
end;
end.