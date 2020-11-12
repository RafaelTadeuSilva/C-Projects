Program Pzim ;
const N = 5;
var mat : array [1..N, 1..N] of integer;
i, j, num, volta : integer;
Begin
	i := 1;
	j := 1;
	num := 0;
	volta := 1;
	while volta <= N do
	begin
	
		//para a direita
		for j:=j to N+1 - volta do
		begin
			num := num + 1;
			mat[i, j] := num;
		end;

		//para baixo
		for i:=i+1 to N do
		begin
			num := num + 1;
			mat[i, j] := num
		end;		  
		
		//próxima volta
		volta := volta + 1;
		i := volta;
		j := 1;

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