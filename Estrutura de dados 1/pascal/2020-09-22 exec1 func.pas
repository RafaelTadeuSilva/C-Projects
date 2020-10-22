Program Pzim ;
type 
TRect = record
	base: real;
	altura: real;
end;

function CalcPerimetro(rect:TRect) : real;
begin
 	CalcPerimetro:= 2*(rect.base+rect.altura);
end;

function CalcArea(rect:TRect) : real;
begin
 	CalcArea:= rect.base*rect.altura;
end;

var 
	rect : TRect;

Begin
	write('Digitar a base: ');
	readln(rect.base);                          
	write('Digitar a altura: ');
	readln(rect.altura);
	
	writeln('Perimetro do Retangulo: ',CalcPerimetro(rect):0:2);
	write('Area do Retangulo: ',CalcArea(rect):0:2);
End.