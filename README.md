# intro-Mertens-Function-Integer-Factorization-Analyzer-in-C-.1


Mertens Function & Integer Factorization Analyzer in C
A robust C program developed as an introductory programming assignment, focusing on number theory concepts without relying on floating-point arithmetic, arrays, pointers, or external math libraries.

Key Features:

•Square-Free Numbers & Möbius Function ($\mu$): Evaluates whether integers are square-free and computes Möbius values based on prime factor counts.

•Mertens Function ($M$) & Zero Points: Computes the Mertens function up to $10^{\text{MAXEXP}} + 9$ and tracks its zero-crossing points ($ZP$).

•Classification of Integers: Analyzes the range $[2, ZP \times 1000]$ to efficiently classify numbers into Perfect, Deficient, or Abundant using sum-of-divisors prime factorization theorems.

•Compilation Flexibility: Supports dynamic parameterization of the exponent (MAXEXP) via compiler definitions (-DMAXEXP=...).
