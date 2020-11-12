Program Pzim ;
const N = 5;
var mat : array [1..N, 1..N] of integer;
i, j, num, volta, limite : integer;

Begin
	i := 1;
	j := 1;
	num := 0;
	volta := 1;
	while volta <= N-2 do
	begin
		//para a direita
		for j:=j to N+1 - volta do
		begin
			num := num + 1;
			mat[i, j] := num;
		end;
		
   	//para baixo
		for i:=i+1 to N+1 - volta do
		begin
			num := num + 1;
			mat[i, j] := num
		end;
		
		//para esquerda
		for j:=j-1 downto volta do
		begin
			num := num + 1;
			mat[i, j] := num
		end;
		
		//para cima
		for i:=i-1 downto volta + 1 do
		begin
			num := num + 1;
			mat[i, j] := num
		end;

		//próxima volta
		volta := volta + 1;
		j:= volta;
	end;
			 
	for i := 1 to N do
	begin
		for j := 1 to N do
		begin
			write(mat[i,j], '	');
		end;
		writeln;
	end;	
	readkey;
End.