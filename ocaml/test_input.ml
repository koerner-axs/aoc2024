let () =
  try
    while true do
      (* Read a line from stdin *)
      let line = input_line stdin in

      (* Convert each character to its hexadecimal representation *)
      String.iter
        (fun c -> Printf.printf "%02x " (Char.code c))
        line;

      (* Print a newline after each line of input *)
      print_newline ();
    done
  with End_of_file ->
    (* End of input reached *)
    ()
