Program Pzim ;

const N = 5;

var
mat : array[1..N,1..N] of integer;
i: integer;
j: integer;
num:integer;
volta :integer;

Begin
  i:= 1;
  volta :=1;
  
  while(num < 25)do
  begin
    
    //esquerda
    for j:= N downto 1 + volta -1 do
    begin
      num:= num + 1;
      mat[i][j] := num;
    end;
    
    if (num >= 25) then
    break;
    
    //baixo
    for i:= 1 + volta to N + 1 - volta do
    begin
      num:=num+1;
      mat[i][j] := num;
    end;
    
    //direira
    for j:= 1 + volta to N do
    begin
      num := num + 1;
      mat[i][j] := num;
    end;
    
    volta:= volta + 1;
    i := volta;
    
  end;
  
  for i :=1 to N do
  begin
    for j :=1 to N do
    write(mat[i][j], '	');
    writeln();
  end;
End.