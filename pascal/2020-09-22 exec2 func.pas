Program Pzim ;

function CalcMaxPrestacao(salario: real):real;
begin
	CalcMaxPrestacao := salario * 0.3;
end;

procedure VerifPrestacao();
var
	salario:real; 
	prestacao:real;
begin
	write('Informe o salario: ');
	readln(salario);
	write('Informe o valor da prestacao: ');
	readln(prestacao);
	if(prestacao > CalcMaxPrestacao(salario)) then
		write('Emprestimo Negado! Prestacao ultrapassa limite do salario.')
	else
		write('Emprestimo Autorizado!');
end;

Begin
  VerifPrestacao();
End.