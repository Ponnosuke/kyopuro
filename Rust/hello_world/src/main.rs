fn main() {
    let mut array = [10, 20, 30];
    for i in &mut array {
        *i += 1;
    }
    assert_eq!(array, [11, 21, 31]);
}