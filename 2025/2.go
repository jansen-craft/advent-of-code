package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func duplicated(s string) bool {
	return s[:len(s)/2] == s[len(s)/2:]
}

func periodic(s string) bool { // repeated substring pattern
	if len(s) < 2 {
		return false
	}
	ss := (s + s)[1 : len(s)*2-1]
	return strings.Contains(ss, s) // if ababab in -bababababa- then its periodic
}

func Day2() {
	scanner := bufio.NewScanner(os.Stdin)

	scanner.Scan()
	line := scanner.Text()
	fmt.Println(line)

	sum := 0
	sum2 := 0

	parts := strings.Split(line, ",")

	for _, part := range parts {
		nums := strings.SplitN(part, "-", 2)
		start, _ := strconv.Atoi(nums[0])
		end, _ := strconv.Atoi(nums[1])

		for ; start <= end; start++ {
			if duplicated(strconv.Itoa(start)) {
				fmt.Printf("duplicated: %d\n", start)
				sum += start
			}

			if periodic(strconv.Itoa(start)) {
				fmt.Printf("periodic: %d\n", start)
				sum2 += start
			}
		}
	}

	fmt.Printf("Sum of duplicated: %d\n", sum)
	fmt.Printf("Sum of periodic: %d\n", sum2)
}
