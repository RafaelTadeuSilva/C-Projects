Program Pzim ;

procedure escreveLinha(linha:string);
begin
	writeln(linha);
end;

function retornaTexto(qtChar : integer):string;
var
	texto :string;
	i:integer;
begin
	for i:= 1 to qtChar do
	begin
		texto := concat(texto, '*');
	end;
	retornaTexto := texto;	
end;

var 
	i : integer;
Begin
  for i:= 0 to 6 do
  begin
  	escreveLinha(retornaTexto(i));
  end;
End.