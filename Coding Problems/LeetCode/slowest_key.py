class Solution(object):
    def slowestKey(self, releaseTimes, keysPressed):
        """
        :type releaseTimes: List[int]
        :type keysPressed: str
        :rtype: str
        """
        longest_duration = releaseTimes[0]
        longest_pressed_key = keysPressed[0]
        for i in range(1,len(releaseTimes)):
            if releaseTimes[i] - releaseTimes[i - 1] > longest_duration:
                longest_duration = releaseTimes[i] - releaseTimes[i - 1]
                longest_pressed_key = keysPressed[i]
            elif releaseTimes[i] - releaseTimes[i - 1] == longest_duration:
                if keysPressed[i] > longest_pressed_key:
                    longest_pressed_key = keysPressed[i]
        return longest_pressed_key
