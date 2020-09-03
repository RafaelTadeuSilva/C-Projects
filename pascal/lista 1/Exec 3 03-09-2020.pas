Program Pzim ;
var mat : array [1..5, 1..5] of integer;
i, j, num, rodada : integer;
Begin
	i := 1;
	j := 1;
	num := 1;
	rodada := 1;
	while num <= 25 do
	begin
		mat[i, j] := num;
		num := num + 1;
		j := j + 1;
		if(j = 6 - rodada) then
		begin
			while i < 6 do
			begin
				mat[i, j] := num;	
				num := num + 1;
				i := i+1;
			end;
		  rodada := rodada + 1;
			i := rodada;
			j := 1;
		end;
	end;
			 
	for i := 1 to 5 do
	begin
		for j := 1 to 5 do
		begin
			write(mat[i,j], '	');
		end;
		writeln;
	end;	
	readkey;
End.