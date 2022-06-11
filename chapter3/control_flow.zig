const std = @import("std");

pub fn main() void {
    std.log.debug("{d}", .{binsearch(0, &[_]u32{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 })});
}

fn binsearch(x: u32, input: []const u32) ?usize {
    var offset: usize = 0;
    var v = input;

    while (true) {
        const i = v.len / 2;
        if (i >= v.len) return null;
        if (x > v[i]) {
            v = v[i..];
            offset += i;
        } else if (x < v[i]) {
            v = v[0..i];
        } else {
            return offset + i;
        }
        if (v.len == 1)
            // We're stuck
            return null;
    }
}
