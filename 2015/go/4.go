package main

import (
	"crypto/md5"
	"fmt"
	"io"
	"os"
	"strconv"
)

func Day4() {
	b, _ := io.ReadAll(os.Stdin)
	secret := string(b[:len(b)-1])

	for i := 1; ; i++ {
		data := secret + strconv.Itoa(i)
		hash := md5.Sum([]byte(data))
		hexHash := fmt.Sprintf("%x", hash) // to hex

		// if hexHash[:5] == "00000" {
		// 	fmt.Printf("p1: %d\n", i)
		// 	break
		// }

		if hexHash[:6] == "000000" {
			fmt.Printf("p2: %d\n", i)
			break
		}
	}
}
