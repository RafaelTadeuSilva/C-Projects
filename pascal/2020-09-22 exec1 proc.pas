Program Pzim ;
type
	TRect = record
		base: real;
		altura: real;
		perimetro: real;
	end;

procedure CalcPerimetro(rect: TRect);
Begin
	write('Digitar a base: ');
	readln(rect.base);                          
	write('Digitar a altura: ');
	readln(rect.altura);
	rect.perimetro := 2*(rect.base+rect.altura);
	write('Perimetro do Retangulo: ',rect.perimetro:0:2);
end;
var rect : TRect;

Begin
	CalcPerimetro(rect);  
End.