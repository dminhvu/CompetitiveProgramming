class Solution(object):
    def squareIsWhite(self, coordinates):
        """
        :type coordinates: str
        :rtype: bool
        """
        coordinates = coordinates[:1] + " " + coordinates[1:]
        total = 0
        for i, c in enumerate(['a','b','c','d','e','f','g','h']):
            if c in coordinates:
                total += (i + 1)
        total += int(coordinates[2])
        return total % 2 == 1
