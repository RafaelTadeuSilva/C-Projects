Program Pzim ;
type
	TAluno = record
		CPF : string;
		NOME : string;
		NOTAS : array [1..3] of real;
	end;
var 
	aluno : TAluno;
	i:integer;
	media: real;
Begin
  write('Digite o CPF do aluno: ');
  readln(aluno.CPF);
  write('Digite o NOME do aluno: ');
  readln(aluno.NOME);
  for i:=1 to 3 do
  begin
	  write('Digite a NOTA ', i ,' do aluno: ');
	  readln(aluno.NOTAS[i]);
	  media := media + aluno.NOTAS[i];
  end;
  writeln();
  writeln('CPF: ', aluno.CPF);
  writeln('NOME: ', aluno.NOME);
  writeln('MEDIA: ', media/3:0:2);
  
End.