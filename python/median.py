def median(a, b):
    len_a, len_b = len(a), len(b)
    if len_a > len_b:
        a, b, len_a, len_b = b, a, len_b, len_a
        
    if len_b == 0 :
        if len_a % 2 == 1:
            return a[len_a / 2]
        else:
            return (a[len_a / 2] + a[len_a / 2 - 1]) / 2.0
        
    start = 0
    end = len_a
    half_len = (len_a + len_b + 1) / 2
    while start <= end:
        mid_a = (start + end) / 2
        mid_b = half_len - mid_a
        if mid_b < len_b and mid_a > 0 and a[mid_a - 1] > b[mid_b]:
            end = mid_a - 1
        elif mid_a < len_a and mid_b > 0 and b[mid_b - 1] > a[mid_a]:
            start = mid_a + 1
        else:
            if mid_a == 0:
                max_left = b[mid_b - 1]
            elif mid_b == 0:
                max_left = a[mid_a - 1]
            else:
                max_left = max(a[mid_a - 1], b[mid_b-1])
            
            if (len_a + len_b) % 2 == 1:
                return max_left
            
            if mid_a == len_a:
                min_right = b[mid_b]
            elif mid_b == len_b:
                min_right = a[mid_a]
            else:
                min_right = min(a[mid_a], b[mid_b])

            return (max_left + min_right) / 2.0

#ANSWER:
#https://discuss.leetcode.com/topic/4996/share-my-o-log-min-m-n-solution-with-explanation/2
 def median(A, B):
    m, n = len(A), len(B)
    if m > n:
        A, B, m, n = B, A, n, m
    if n == 0:
        raise ValueError

    imin, imax, half_len = 0, m, (m + n + 1) / 2
    while imin <= imax:
        i = (imin + imax) / 2
        j = half_len - i
        if j > 0 and i < m and B[j-1] > A[i]:
            # i is too small, must increase it
            imin = i + 1
        elif i > 0 and j < n and A[i-1] > B[j]:
            # i is too big, must decrease it
            imax = i - 1
        else:
            # i is perfect
            if i == 0: max_of_left = B[j-1]
            elif j == 0: max_of_left = A[i-1]
            else: max_of_left = max(A[i-1], B[j-1])

            if (m + n) % 2 == 1:
                return max_of_left

            if i == m: min_of_right = B[j]
            elif j == n: min_of_right = A[i]
            else: min_of_right = min(A[i], B[j])

            return (max_of_left + min_of_right) / 2.0
            