Program Pzim ;
var
	vetor : array[1..10] of integer;
	m : integer;
	i: integer;
	posicao : integer;
Begin
	for i:= 1 to 10 do
  	vetor[i] := 2*i;

	while(true)do
 	begin
 		posicao := 0;
 		write('Digite o valor procurado: ');
 		readln(m);
 		if(m<0)then
 			break;
 		for i:=1 to 10 do
 		begin
 			if(vetor[i] = m)then
 			begin
			 	posicao := i;
			 	break;
 			end;	
 		end;
 		if(posicao > 0) then
 			writeln('Valor encontrado na posicao ', posicao)
 		else
 			writeln('Valor nao encontrado!');
 		writeln();
 		
	end;
	write('Fim da Execucao');		 
End.