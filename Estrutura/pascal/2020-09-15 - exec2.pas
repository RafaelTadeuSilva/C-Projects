Program Pzim ;
function FCelsiusToFarenheit(c:real) : real;
var
	f: real;
begin
	f:= (9*c/5)+32;
	       FCelsiusToFarenheit := f;
end;
var
	c_grau, f_grau: real;
	
Begin
  write ('Digite Celsius');
  readln(c_grau);
  f_grau := FCelsiusToFarenheit (c_grau);
  writeln('Fareh', f_grau:0:2);
  readln;
End.