Program Pzim ;

function somar(a:real; b:real):real;
begin
	somar := a+b;
end;
function subtrair(a:real; b:real):real;
begin
	subtrair := a-b;
end;
function multiplicar(a:real; b:real):real;
begin
	multiplicar := a*b;
end;
function dividir(a:real; b:real):real;
begin
	dividir := a/b;
end;

procedure ImprimeMenu();
var 
	a:real;
	b:real;
	opcao:integer;
begin
	write('Digite o valor de a: ');
	readln(a);
	write('Digite o valor de b: ');
	readln(b);
	writeln();
	writeln('Digite 1 para somar');
	writeln('Digite 2 para subtrair');
	writeln('Digite 3 para multiplicar');
	writeln('Digite 4 para dividir');
	readln(opcao);
	writeln();	               
	write('Resultado: ');	
	if(opcao = 1) then
		writeln(a:0:2,' + ',b:0:2,' = ', somar(a, b):0:2)
	else if(opcao = 2) then
		writeln(a:0:2,' - ',b:0:2,' = ', subtrair(a, b):0:2)
	else if(opcao = 3) then
		writeln(a:0:2,' * ',b:0:2,' = ', multiplicar(a, b):0:2)
	else if(opcao = 4) then
	begin
		if(b=0)then
			writeln('Divisao por 0: Resultado Indeterminado!')
		else
			writeln(a:0:2,' / ',b:0:2,' = ', dividir(a, b):0:2)
	end
	else
	  writeln('Opcao inválida');
	  
end;

Begin
  ImprimeMenu();
End.