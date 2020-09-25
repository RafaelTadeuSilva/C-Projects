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

var 
	rect : TRect;

Begin
	write('Digitar a base: ');
	readln(rect.base);                          
	write('Digitar a altura: ');
	readln(rect.altura);
	
	write('Perimetro do Retangulo: ',CalcPerimetro(rect):0:2);
End.