#!/usr/bin/env python3
import itertools
import subprocess
import sys

def test_all_permutations():
    """Test all 120 permutations of [0, 1, 2, 3, 4] with push_swap"""
    
    numbers = [0, 1, 2, 3, 4]
    total_permutations = 0
    max_operations = 0
    max_perm = None
    results = []
    
    print("Testing all permutations of [0, 1, 2, 3, 4] ...")
    print("=" * 50)
    
    for perm in itertools.permutations(numbers):
        total_permutations += 1
        
        # Convert tuple to space-separated string
        args = ' '.join(map(str, perm))
        
        try:
            # Run push_swap with the current permutation
            result = subprocess.run(
                ['./push_swap'] + list(map(str, perm)),
                capture_output=True,
                text=True,
                timeout=5
            )
            
            if result.returncode == 0:
                # Count the number of operations
                operations = result.stdout.strip().split('\n') if result.stdout.strip() else []
                num_operations = len(operations)
                
                results.append((perm, num_operations))
                
                # Track maximum operations
                if num_operations > max_operations:
                    max_operations = num_operations
                    max_perm = perm
                
                print(f"Permutation {perm}: {num_operations} operations")
                
                # Check if it exceeds the expected limit for 5 numbers (should be <= 12)
                if num_operations > 12:
                    print(f"WARNING: Exceeds 12 operations!")
                
            else:
                print(f"Permutation {perm}: ERROR - {result.stderr.strip()}")
                
        except subprocess.TimeoutExpired:
            print(f"Permutation {perm}: TIMEOUT")
        except FileNotFoundError:
            print("Error: push_swap executable not found. Make sure it's compiled and in the current directory.")
            return
        except Exception as e:
            print(f"Permutation {perm}: EXCEPTION - {e}")
    
    # Summary
    print("\n" + "=" * 50)
    print("SUMMARY")
    print("=" * 50)
    print(f"Total permutations tested: {total_permutations}")
    print(f"Maximum operations needed: {max_operations}")
    print(f"Worst case permutation: {max_perm}")
    
    # Statistics
    if results:
        operation_counts = [ops for _, ops in results]
        avg_operations = sum(operation_counts) / len(operation_counts)
        print(f"Average operations: {avg_operations:.2f}")
        
        # Count permutations by operation count
        from collections import Counter
        op_distribution = Counter(operation_counts)
        print("\nOperation count distribution:")
        for ops in sorted(op_distribution.keys()):
            count = op_distribution[ops]
            print(f"  {ops} operations: {count} permutations")
        
        # Show permutations that exceed 12 operations
        bad_perms = [(perm, ops) for perm, ops in results if ops > 12]
        if bad_perms:
            print(f"\n{len(bad_perms)} permutations exceed 12 operations:")
            for perm, ops in bad_perms:
                print(f"	{perm}: {ops} operations")
        else:
            print("\nAll permutations use 12 or fewer operations!")

if __name__ == "__main__":
    test_all_permutations()