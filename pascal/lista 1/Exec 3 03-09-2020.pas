Program Pzim ;
const N = 5;
var mat : array [1..N, 1..N] of integer;
i, j, num, diag : integer;
Begin
	i := 1;
	j := 1;
	num := 1;
	diag := 1;
	while diag <=N do
	begin
		
		//preenche a diagonal 1
		if diag = 1 then
			mat[i, j] := num
		else //preenche as demais diagonais
		begin
		  mat[i, j] := num;
		  mat[j, i] := num;
		end;
		
		num := num + 1;
		j := j + 1;
		i := i + 1;
		
		//Se a coluna passar da ultima coluna
		if(j = N+1) then
		begin
			//muda para a proxima diagonal
			diag := diag + 1;
			i:= 1;
			j:= diag;
		end;
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