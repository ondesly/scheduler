// swift-tools-version: 5.9
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "scheduler",
    products: [
        .library(name: "scheduler", targets: ["c_scheduler"]),
    ],
    targets: [
        .target(
            name: "c_scheduler",
            path: "src",
            sources: [
                "scheduler/schedule_handler.cpp",
                "scheduler/scheduler.cpp"
            ],
            publicHeadersPath: "."
        )
    ],
    cxxLanguageStandard: .cxx17
)
