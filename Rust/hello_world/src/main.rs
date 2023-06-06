fn main() {
    let x = 10;
    let y = 10;
    let z = std::cmp::max(&x, &y);
    // 2 つの値が等しいので，返り値は &y になる
    println!("&x: {:p}", &x);
    println!("&y: {:p}", &y);
    println!("z:  {:p}", z);
}