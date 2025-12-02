package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func norm(a, M int) int {
	return (a%M + M) % M
}

func floorDiv(a, b int) int {
	q := a / b
	if a < 0 && a%b != 0 {
		q-- // floor for negatives
	}
	return q
}

func zeroCrossings(a, delta, M int) int {
	a = norm(a, M)
	s := a + delta

	if delta > 0 {
		// multiples of M in (a, s]
		// 						    a     Δ     s
		// (a, s]				    ○▬▬▬▬▬▬▬▬▬▬▬●
		return floorDiv(s, M) - floorDiv(a, M)
	} else if delta < 0 {
		// multiples of M in [s, a)
		//				s     Δ     a
		// [s, a)		●▬▬▬▬▬▬▬▬▬▬▬○
		// (s-1, a-1]  ○▬▬▬▬▬▬▬▬▬▬▬●  (aka)
		return floorDiv(a-1, M) - floorDiv(s-1, M)
	}
	return 0
}

func main() {
	const M = 100
	scanner := bufio.NewScanner(os.Stdin)
	index := 50
	zeroLands := 0
	zeroPasses := 0

	for scanner.Scan() {
		line := scanner.Text()
		if line == "" {
			continue
		}

		num, _ := strconv.Atoi(line[1:])

		if line[0] == 'L' {
			newIndex := norm(index-num, M)
			crosses := zeroCrossings(index, -num, M)
			zeroPasses += crosses
			fmt.Printf("%3d L %3d = %3d", index, num, newIndex)
			if crosses > 0 {
				fmt.Printf(" (%d)", crosses)
			}
			fmt.Println()
			index = newIndex
		} else if line[0] == 'R' {
			newIndex := norm(index+num, M)
			crosses := zeroCrossings(index, num, M)
			zeroPasses += crosses
			fmt.Printf("%3d R %3d = %3d", index, num, newIndex)
			if crosses > 0 {
				fmt.Printf(" (%d)", crosses)
			}
			fmt.Println()
			index = newIndex
		}

		if index == 0 {
			zeroLands++
		}
	}

	fmt.Println("\nFinal index:", index)
	fmt.Println("0 land count:", zeroLands)
	fmt.Println("0 pass count:", zeroPasses)

	if err := scanner.Err(); err != nil {
		fmt.Fprintln(os.Stderr, "read error:", err)
	}
}
