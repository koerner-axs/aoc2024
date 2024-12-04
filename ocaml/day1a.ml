let () =
    let open Text.IO in
    let input = stdin () in

    let l1 = ref [] in
    let l2 = ref [] in

    let () =
        try
            while true do
                let line = read_line input in
                let a, b = Scanf.sscanf line "%d %d" (fun a b -> a, b) in
                l1 := a :: !l1;
                l2 := b :: !l2
            done
        with End_of_file ->
            ()
        in

    let sorted_l1 = List.sort compare !l1 in
    let sorted_l2 = List.sort compare !l2 in

    let sum =
        List.fold_left2
        (fun acc x y ->
            let diff = abs (x - y) in
            Printf.printf "%d %d diff=%d\n" x y diff;
            acc + diff)
            0 sorted_l1 sorted_l2
        in

    Printf.printf "Total difference sum: %d\n" sum
