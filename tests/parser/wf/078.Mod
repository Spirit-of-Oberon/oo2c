MODULE M;
BEGIN
  CASE x OF
  | 10: y := 1
  | 20: y := 2
  ELSE
    y := 3
  END
END M.
