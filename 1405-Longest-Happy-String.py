import heapq

class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        # Initialize max-heap with negative counts for 'a', 'b', 'c'
        heap = []
        if a > 0:
            heapq.heappush(heap, (-a, 'a'))
        if b > 0:
            heapq.heappush(heap, (-b, 'b'))
        if c > 0:
            heapq.heappush(heap, (-c, 'c'))
        
        result = []
        last_char = ''
        last_char_count = 0
        
        while heap:
            count, char = heapq.heappop(heap)
            count = -count  # Convert back to positive count
            
            if last_char != char or last_char_count < 2:
                # Safe to add the character
                result.append(char)
                last_char_count = last_char_count + 1 if last_char == char else 1
                last_char = char
                count -= 1  # Decrease the count
                
                if count > 0:
                    heapq.heappush(heap, (-count, char))
            else:
                # Need to try the next character
                if not heap:
                    # No other character to use
                    break
                count_next, char_next = heapq.heappop(heap)
                count_next = -count_next  # Convert back to positive count
                
                # Add the next character
                result.append(char_next)
                last_char_count = 1
                last_char = char_next
                count_next -= 1
                
                if count_next > 0:
                    heapq.heappush(heap, (-count_next, char_next))
                # Push the first character back into the heap
                heapq.heappush(heap, (-count, char))
        
        return ''.join(result)

        