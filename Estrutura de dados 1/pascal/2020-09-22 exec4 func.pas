Program Pzim ;

const valDiaria = 80;

function CalcSalLiquido(qtDias :integer):real;
begin
	CalcSalLiquido := valDiaria*qtDias*0.92;
end;                                                      

var
	qtDias : integer;

Begin
	write('Digite quanto dias o encanador trabalhou: ');
	readln(qtDias);
	
	write('Salario Liquido: R$ ', CalcSalLiquido(qtDias):0:2);
End.