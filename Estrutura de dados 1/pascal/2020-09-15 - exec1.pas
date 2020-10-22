Program Pzim ;

type
TEquacao = record
  x1: real;
  x2: real;
end;
function FDelta(a: real; b: real; c:real):real;
begin
  FDelta := b*b - 4*a*c;
end;

function FCalcular(a: real; b:real;c:real) : TEquacao;
var 
	d :real;
	raizes : TEquacao;
begin
	raizes.x1 :=999;
  raizes.x2 :=999;
  
  if(a = 0) then
  	writeln('Divisao por zero!')
  else
  begin
  	d := FDelta(a,b,c);
  	if(d<0) then
  		writeln('Não existem raizes reais')
  	else
		begin
			raizes.x1 := -(b + sqrt(d)) /(2*a);
			raizes.x2 := -(b - sqrt(d)) /(2*a);
		end;
	end;
	FCalcular := raizes;  	
end;	

var a,b, c: real;
r: TEquacao;

Begin

	write('Digite A');
	readln(a);
	write('Digite B');
	readln(b);
		write('Digite C');
	readln(c);
	
	r:= FCalcular(a,b,c);
	
	writeln('X1: ', r.x1:0:2);
	writeln('X2: ', r.x2:0:2);
End.