# install.packages("devtools")
# devtools::install_github("akondrashov96/rusmaps")

# library(maps)
# library(mapdata)
# library(sf)
library(ggplot2)

# library(tidyr)
# library(zoo)
# library(RColorBrewer)
# library(scales)

library(jsonlite)
library(dplyr)


library(rusmaps)

df <- rusmaps.dataframe




cards <- read.table(file = "R/__tmp__/saferoads/cards_short.tsv", sep = "\t", header = TRUE)
regions <- read.table(file = "R/__tmp__/saferoads/regions.tsv", sep = "\t", header = TRUE)





# library(sp)


lines <- lapply(readLines("R/__tmp__/saferoads/saferoads_short.jsonl"), fromJSON)
saferoads <- bind_rows(lapply(lines, unlist))

pdf(file = "1.pdf")
# plot(rus_sub)
# plot(cities, color = "red")
# map <- rus_sub

ggplot(rus_sub) +
    geom_sf()

# ggplot() + geom_polygon(data = rus_sub, aes(x = long, y = lat, group = group),
#         color = "black", fill = "white")


dev.off()

# readLines()
# install.packages("Rcpp")
# library(Rcpp)
# install.packages("sf")
# library(sf)